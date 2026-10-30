# Convert - Запустить процесс конвертации

[API интерфейсов. Версия 7](applicate.html) > [Конвертер файлов КОМПАС ](conv.html) > [Интерфейс IСonverter ](iconverter.html) > [IConverter - методы ](iconverter_methods.html) |  Scroll [ [ [ ](iconverter_converterparameters.html "К следующему разделу")](iconverter_methods.html "На уровень выше")](iconverter_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconverter.html)

Синтаксис Automation:

long * Convert (BSTR inputFile, BSTR outfile, long command, BOOL showParam);

Синтаксис COM:

HRESULT Convert ([in] BSTR inputFile,

[in] BSTR outfile,

[in] long command,

[in] VARIANT_BOOL showParam,

[out, retval] long* Result);

Входные параметры:

inputFile | \- имя исходного файла документа,  
---|---  
outfile | \- новое имя файла документа,  
command | \- номер команды,  
showParam | \- TRUE - выдавать диалог параметров конвертации, FALSE - не выдавать диалог параметров конвертации.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если имя исходного файла документа не задано, то берется текущий документ. Если новое имя файла документа не задано, то конвертация будет происходить в новый документ системы КОМПАС.

Подразделы:

(отсутствуют)
