# ksExecuteLibraryCommand - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char fileName[255];

::strcpy(fileName, "C:\\\libtest\\\libtest.rtw"); // имя файла библиотеки

ksExecuteLibraryCommand(fileName, 3/*номер команды*/);

// выполнение команды 3 из библиотеки
