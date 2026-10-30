# WriteFragment - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//Пример использования WriteFragment

double x, y, x1,y1;

RequestInfo info;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите начальную точку окна";

if (Cursor(&info, &x, &y, 0))

{

info.prompt = "Укажите конечную точку окна";

if (Cursor(&info, &x1, &y1, 0))

{

//создадим рабочую группу

reference gr = NewGroup(0);

EndGroup();

if (SelectGroup(gr, 1, x, y, x1, y1))

{

LightObj(gr, 1);//подсветим выделенную группу

char name[128];

//запросить имя файла фрагмента

if(SaveFile("*.frw",0,0, name,128))

{

info.prompt = "Укажите точку привязки фрагмента";

if (Cursor(&info, &x, &y, 0))

{

//записать содержимое группы во фрагмент

WriteFragment(gr, name, "фрагмент из рабочей группы", x, y);

Message("Фрагмент записан");

}

}

LightObj(gr, 0);//снять подсветку выделенной группы

}

}

}
