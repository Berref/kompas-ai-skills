# ksGetZona пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
RequestInfo info;

K ksGetZona

//обнулить структуру info;

memset (&info, 0, sizeof (info));

double x, y;

info.prompt = "Укажите точку";

char zona [128];

while (Cursor (&info, &x, &y, 0) == -1) {

int rez = ksGetZona(x, y, zona, 128); //размер присланного буфера

if (rez == -1 || !rez) {

Error(rez ? "В текущем документе нет разбиения на зоны" : "Ошибка");

break;

}

else

Message (zona);

}
