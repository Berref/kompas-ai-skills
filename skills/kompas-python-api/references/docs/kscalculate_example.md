# ksCalculate, ksCalculateReset - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//очистить массив переменных

ksCalculateReset ();

char buf [128];

double resD;

//добавить переменную A1 = 100

int rezI = ksCalculate ("A1 = 100", &resD);

sprintf (buf,"resD = %f rezI = %d", resD, rezI);

Message (buf);

//добавить переменную A2 = 200

rezI = ksCalculate ("A2 = 200", &resD);

sprintf (buf,"resD = %f rezI = %d", resD, rezI);

Message (buf);

//подсчитать результат выражения

rezI = ksCalculate ("(A1 A2) * sqrt(4)", &resD);

sprintf (buf,"resD = %f rezI = %d", resD, rezI);

Message (buf);
