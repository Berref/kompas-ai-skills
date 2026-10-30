# ksChoiceFileAppointedDir - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char fileName[ MAX_TEXT_LENGTH ];

if (ksChoiceFileAppointedDir ("*.cdw", // расширение имени файла

"Чертежи(*.cdw)|*.cdw|Фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|",

// фильтр поиска (0 - формируется автоматически)

fileName // буфер для имени файла

MAX_TEXT_LENGTH, // размер отведенного буфера name

1, // -с подключением окна предварительного просмотра,

sptSYSTEM_FILES))

{

OpenDocument (fileName, 0);

}
