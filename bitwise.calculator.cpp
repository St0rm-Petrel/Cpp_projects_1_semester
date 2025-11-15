//
// A bitwise logical expression is much like an arithmetic expression except
// that the operators are ! (not), ~ (complement), & (and), | (or), and ^
// (exclusive or). Each operator does its operation to each bit of its
// integer operands (see §25.5). ! and ~ are prefix unary operators. A ^
// binds tighter than a | (just as * binds tighter than +) so that x|y^z
// means x|(y^z) rather than (x|y)^z. The & operator binds tighter than ^ so
// that x^y&z means x^(y&z).
//

/*
  Grammar of a bitwise logical expression.

  Expression:
    Term
    Expression "|" Term
  Term:
    Subterm
    Term "^" Subterm
  Subterm:
    Primary
    Subterm "&" Primary
  Primary:
    Number
    "(" Expression ")"
    "!" Primary
    "~" Primary
  Number:
    integer_literal

*/


#include <std_lib_facilities.h>

class Token
{
public:
  char kind;     /// what kind of token
  double value;  /// for numbers: a value

  Token (char ch) : kind{ch}, value{0} {}

  Token (char ch, double val) : kind{ch}, value{val} {}
};

class Token_stream
{
public:
  Token_stream ();  /// make a Token_stream that reads from cin

  Token get ();
  void putback (Token t);

private:
  bool full{false};  /// is there a Token in the buffer?
  Token buffer;      /// here we keep a Token put back using putback()
};

Token_stream::Token_stream () : buffer{0}  /// no Token in buffer
{
}

void Token_stream::putback (Token t)
{
  if (full)
    error("putback() into a full buffer");

  buffer = t;
  full = true;
}

Token Token_stream::get ()
{
  if (full)  // do we already have a Token ready?
  {
    full = false;  // remove Token from buffer
    return buffer;
  }

  char ch;
  cin >> ch;  // note that >> skips whitespace (space, newline, tab, ...)

  switch (ch)
  {
  case ';':  // for "print"
  case 'q':  // for "quit"
  case '(':
  case ')':
  case '&':
  case '|':
  case '^':
  case '~':
  case '!':
    return Token{ch};  // let each character represent itself

  case ',':
    ch = '.';
  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  {
    cin.putback(ch);  // put digit back into the input stream
    double val;
    cin >> val;              // read a floating-point number
    return Token{'8', val};  // let '8' represent "a number"
  }

  default:
    error("Bad token");
  }
}

Token_stream ts;

int expression ();


int primary ()
{
  Token t = ts.get();
  switch (t.kind)
  {
  case '(':  // handle '(' expression ')'
  {
    int d = expression(); // здесь мы производим операцию в скобках
    t = ts.get(); // здесь считываем очередное значение
    if (t.kind != ')') // здесь проверяем, является ли оно ")"
      error("')' expected"); // если не является - ошибка
    return d; // возвращаем результат операции в скобках
  }

  case '8':  // we use '8' to represent a number
    return t.value;
  
  case '~':
    {
      int left = ~primary();
      return left;
    }
  case '!':
    {
      int left = !primary();
      return left;
    }

  default:
    error("primary expected"); // ошибка - ожидался примитив
  }
}


int subterm()
{
    int left = primary();
    Token t = ts.get();
    while (true)
  {
    switch (t.kind)
    {
    case '&':
      left &= primary();
      t = ts.get();
      break;

    default:
      ts.putback(t);  // put t back into the token stream
      return left;
    }
  }

}

/// deal with &
int term ()
{
  int left = subterm();
  Token t = ts.get();  // get the next token from token stream

  while (true)
  {
    switch (t.kind)
    {
    case '^':
      left ^= subterm();
      t = ts.get();
      break;

    default:
      ts.putback(t);  // put t back into the token stream
      return left;
    }
  }
}

/// deal with ~
int expression ()
{
  int left = term();  // read and evaluate a Term
  Token t = ts.get();    // get the next token from token stream

  while (true)
  {
    switch (t.kind)
    {

    case '|':
      left |= term();  // evaluate Term and subtract
      t = ts.get();
      break;

    default:
      ts.putback(t);  // put t back into the token stream
      return left;    // finally: no more + or -: return the answer
    }
  }
}

int main ()
try
{
  double value = 0;
  while (cin)
  {
    Token t = ts.get();
        
    if (t.kind == 'q')
      break;            // 'q' for quit
    if (t.kind == ';')  // ';' for "print now"
      {
        cout << "=" << value << '\n';
      }
    else
      ts.putback(t);
    value = expression();
  }
}
catch (exception& e)
{
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Oops: unknown exception!\n";
  return 2;
}
