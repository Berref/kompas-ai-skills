# ksGetLibraryStylesArray - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//получим массив оформлений для графических документов из библиотеки graphic.lyt

reference styleArr = ksGetLibraryStylesArray ("d:\\\Kompas56\\\Sys\\\graphic.lyt",

GRAPHIC_LAYOUT_STYLE_LIBRARY);// библиотека оформлений

if (styleArr)

{

char buf[128];

//определим количество стилей и отобразим на экране

int count = GetArrayCount(styleArr);

sprintf(buf, "count = %d", count);

Message(buf);

//в цикле получим информацию о каждом стиле и отобразим на экране

for (uint i = 0; i < count; i++)

{

LibraryStyleParam par;

GetArrayItem (styleArr, // указатель на массив

i, // индекс в массиве (нумерация начинается с 0)

&par, // указатель на структуру элемента

sizeof (LibraryStyleParam)); // размер структуры элемента

sprintf(buf, "ID = %d\nname=%s", par.styleId, par.styleName);

Message(buf);

}

}
