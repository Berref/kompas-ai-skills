# ksGetMacroEditParam - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Macro (0);

Point (10, 10, 1);

reference ref = EndObj ();

SetMacroParam (ref, NULL, 0, "FileName.rtw", "LibName", 111);

char fileName[128]; // буфер имени файла библиотеки

unsigned int fileNameSize = sizeof (fileName); // размер буферa имени файла библиотеки

char libName[128]; // буфер имени библиотеки

unsigned int libNameSize = sizeof (libName); // размер буферa имени библиотеки

int number; // буфер номерa функции редактирования

int res = ksGetMacroEditParam (ref, fileName, fileNameSize, libName,

libNameSize, &number);

if (res) {

char buf[128];

sprintf (buf, " Имя файла: %s\n Имя библиотеки: %s\n Номер функции: %i",

fileName, libName, number);

Message (buf);

}

else

Error ("Ошибка");
