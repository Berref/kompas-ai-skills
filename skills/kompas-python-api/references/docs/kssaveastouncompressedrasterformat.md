# ksSaveAsToUncompressedRasterFormat - Сохранить документ в растровом формате без сжатия

[API экспортных функций](export_function.html) > [Функции экспорта документов ](impex_fncts_common.html) |  Scroll [ [ [ ](kssaveastouncompressedrasterformatw.html "К следующему разделу")](impex_fncts_common.html "На уровень выше")](kssaveastorasterformatw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::SaveAsToUncompressedRasterFormat](ksdocument2d_saveastouncompressedrasterformat.html).

Синтаксис:

int ksSaveAsToUncompressedRasterFormat (reference pDoc,

char * fileName,

RasterFormatParam * par);

Входные параметры:

pDoc | \- указатель на документ,  
---|---  
fileName | \- имя файла документа, должно быть задано полное имя файла,  
par | \- структура параметров для конвертации в растровый формат.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция позволяет сохранить документ в растровом формате без сжатия, с заданными свойствами: цветом, форматом (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) и т.п. Подробнее см. описание [RasterFormatParam](structrasterformatparam.html).

охранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

2\. Функция используется для графических документов (чертеж, фрагмент), документов деталей и сборок, для спецификаций и текстовых документов. Для документов деталей и сборок предварительно нужно получить reference, используя функцию [ksGetReferenceFrom3dDocument](ksgetreferencefrom3ddocument.html) для COM или свойство [ksDocument3D::reference](ksdocument3d_reference.html) для Automation.

3\. При использовании Unicode следует использовать функцию [ksSaveAsToUncompressedRasterFormatW](kssaveastouncompressedrasterformatw.html).

Подразделы:

(отсутствуют)
