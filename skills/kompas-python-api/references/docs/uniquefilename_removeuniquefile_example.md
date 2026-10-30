# UniqueFileName, RemoveUniqueFile - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char fileName[255];

char buf[128];

FILE * f;

void CreateSysFile() {

f = fopen(fileName,"rt");

fputs("Это служебная информация",f);

fclose(f);

}

void ReadSysFile() {

f = fopen(fileName ,"rt");

fgets(buf, 128, f);

Message(buf);

fclose(f);

}

void UniqueFile_Example (void) {

//запросили имя служебного файла

UniqueFileName(fileName, 255);

CreateSysFile();

ReadSysFile();

//удалить служебный файл

RemoveUniqueFile(fileName);

}; /* UniqueFile_Example */
