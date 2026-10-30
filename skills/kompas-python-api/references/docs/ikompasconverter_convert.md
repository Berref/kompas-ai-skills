# Convert - Запустить процесс конвертации

[Создание прикладных библиотек ](libraries_create.html) > [Оформление библиотек типа Converter ](cr95008.html) > [Интерфейс IKompasConverter ](ikompasconverter.html) > [IKompasConverter - свойства ](ikompasconverter_props.html) |  Scroll [ [ [ ](ikompasconverter_visualeditconvertparam.html "К следующему разделу")](ikompasconverter_props.html "На уровень выше")](ikompasconverter_getfilter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasconverter.html)

Синтаксис Automation:

long * Convert ( BSTR inputFile, BSTR outfile, long command, BOOL showParam );

Синтаксис COM:

HRESULT Convert ( [in] BSTR inputFile,

[in] BSTR outfile,

[in] long command,

[in] VARIANT_BOOL showParam,

[out, retval] long* Result );

Входные параметры:

inputFile | \- имя исходного файла документа,  
---|---  
outfile | \- новое имя файла документа,  
command | \- номер команды,  
showParam | \- TRUE - выдавать диалог параметров конвертации, \- FALSE - не выдавать диалог параметров конвертации.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если имя исходного файла документа не задано, то берётся текущий документ, если новое имя файла документа не задано, то конвертация будет происходить в новый документ системы КОМПАС.

Подразделы:

(отсутствуют)
