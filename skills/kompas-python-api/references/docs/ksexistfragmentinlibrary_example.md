# ksExistFragmentInLibrary - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char frwName [250];

strcpy (frwName, "C:\\\0\\\Детали.lfr|Фланцы|Исполнение 1");

if (ReadString ("Введите имя фрагмента или папки", // строка приглашения

frwName, 250)) {

int j = ksExistFragmentInLibrary(frwName);

char buf [250];

sprintf (buf, "%s\n%s",frwName, j==0 ? "нет фрагмента или папки" : j==-1 ? "нет библиотеки" : "фрагмент или папка есть");

Message(buf);

}
