# ksSaveFile - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//создать массив строк

reference arrName = CreateArray (CHAR_STR_ARR, 0);

//выберем файлы, которые хотим перезаписать

if (ChoiceFiles ("*.cdw", // расширение имени файла

"Чертежи(*.cdw)|*.cdw|Фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|", // фильтр поиска

//(0 - формируется автоматически)

arrName)) // массив неопределенной длины на строки CHAR_STR_ARR

{

int count = GetArrayCount (arrName);

char fileName[ MAX_TEXT_LENGTH ];

for (uint i = 0; i < count; i++)

{

char oldFileName[ MAX_TEXT_LENGTH ];

//выберем старое имя файла

GetArrayItem (arrName, // указатель на массив

i, // индекс в массиве

//(нумерация начинается с 0)

oldFileName, // указатель на структуру элемента

MAX_TEXT_LENGTH);// размер структуры элемента

//выберем новое имя файла

if (ksSaveFile ("*.cdw", // расширение имени файла

oldFileName, // имя файла по умолчанию

"Чертежи(*.cdw)|*.cdw|Фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|",

// фильтр поиска (0 - формируется автоматически)

fileName, // буфер для имени файла

MAX_TEXT_LENGTH , // размер отведенного буфера name

1)) // 1-с подключением окна

// предварительного просмотра

{

//если новое и старое имя не совпадают, перезапишем документ

if (lstrcmp (oldFileName, fileName))

{

reference doc = OpenDocument (oldFileName, 1);

if (doc)

{

SaveDocument (doc, fileName);

CloseDocument (doc);

}

}

}

else

break;

}

}

//удалить массив

DeleteArray(arrName);
