# FullFileName, GetRightFileName - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void FileName_Example (void) {

char *s2;

//выделим буфер

s2 = new char [6];

strcpy(s2, "1.cdw");

unsigned int size2,size1 ;

//получим полное имя и поместим его в s2

size1=strlen(s2) 1;

if ((size2=FullFileName(s2, s2, size1)) > size1) {

//требуемая длина size2 > size1, которую мы предоставили

delete [] s2;

s2 = new char[size2];

GetRightFileName(s2, size2);

}

}; /* FileName_Example */
