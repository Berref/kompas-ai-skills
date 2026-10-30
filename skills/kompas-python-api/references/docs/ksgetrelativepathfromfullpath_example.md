# ksGetRelativePathFromFullPath - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char mainName[250];

//имя задающего файла

if((::ChoiceFile("*.*", "Все файлы (*.*)|*.*|", mainName, 250))){

char fileName[250];

if((::ChoiceFile("*.*", "Все файлы (*.*)|*.*|", fileName, 250))){

char relName[250];

//относительный путь

::ksGetRelativePathFromFullPath(mainName, //полный путь к задающему файлу

fileName, //полный путь к требуемому файлу

relName, //(результат) относительный путь к требуемому файлу (без общей с задающим файлом части пути)

250); // размер буфера

string mess = "Задающий файл - ";

mess = mainName;

mess = " \n";

mess = "Полный путь -";

mess = fileName ;

mess = " \n";

mess = "Относительный путь -";

mess = relName ;

Message ((char*)mess.c_str());

//полный путь

char fullName[250];

::ksGetFullPathFromRelativePath(mainName, //полный путь к задающему файлу

relName, //относительный путь к требуемому файлу (без общей с задающим файлом части пути)

fullName, //(результат) полный путь к требуемому файлу

250); // размер буфера

mess = "Задающий файл - ";

mess = mainName;

mess = " \n";

mess = "Относительный путь -";

mess = relName ;

mess = " \n";

mess = "Полный путь -";

mess = fullName;

mess = " \n";

Message ((char*)mess.c_str());

}

}
