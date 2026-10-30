# GetMacroParamSize - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference p;

RequestInfo info;

//обнулить структуру info;

memset (&info, 0, sizeof (info));

double x, y;

info.prompt = "Укажите макроэлемент";

int j = Cursor (&info, &x, &y, 0);

if (j) {

if (ExistObj (p = FindObj (x, y, 1e6)) && GetObjParam (p, 0, 0, 0) == MACRO_OBJ) {

int size = GetMacroParamSize (p);

char buf [128];

sprintf (buf, "Размер параметров макроэлемента = %d", size);

Message (buf);

}

}
