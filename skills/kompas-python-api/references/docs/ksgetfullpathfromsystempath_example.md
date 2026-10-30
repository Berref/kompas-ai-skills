# ksGetFullPathFromSystemPath - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char * catalogName[] = {"папка системных файлов",

"папка библиотек",

"папка временных файлов",

"папка конфигурации" ,

"INI-файл" };

//сформировать полный путь к заданному файлу

RequestInfo info;

memset(&info, 0, sizeof(info));

info.title = "Папки файлов системы ";

info.commands = "!Системные !Библиотеки !Временные !Конфигурация !INI-файл ";

info.prompt = "Выберите нужную папку";

int j;

static char *buf = "user.ttt";

char fileName[250];

int typeCatalog;

do {

j = ::CommandWindow(&info);

if (j > 0) {

switch (j) {

case 1 : typeCatalog = sptSYSTEM_FILES; break;// Относительно папки системных файлов

case 2 : typeCatalog = sptLIBS_FILES ; break;// Относительно папки файлов библиотек

case 3 : typeCatalog = sptTEMP_FILES ; break;// Относительно папки сохранения временных файлов

case 4 : typeCatalog = sptCONFIG_FILES; break;// Относительно папки сохранения конфигурации системы

case 5 : typeCatalog = sptINI_FILE ; break;// Относительно полного имени INI-файла системы

}

//полный путь

::ksGetFullPathFromSystemPath(buf , // относительный путь к файлу(без системного пути)

fileName, // (результат) полный путь к файлу

250, // размер буфера

typeCatalog); // путь установленного типа см. ksSystemPath

string mess = "Полный путь к файлу user.ttt \n";

mess = catalogName[j -1];

mess = " :\n";

mess = fileName ;

Message ((char*)mess.c_str());

char relName[250];

//относительный путь

::ksGetRelativePathFromSystemPath(fileName, //полный путь к файлу

relName, //(результат) относительный путь к файлу(без системного пути)

250, //размер буфера

typeCatalog); //путь установленного типа см. ksSystemPath

mess = "Относительный путь к файлу \n";

mess = fileName;

mess = "\n";

mess = catalogName[j -1];

mess = " :\n";

mess = relName;

Message ((char*)mess.c_str());

}

} while (j > 0);
