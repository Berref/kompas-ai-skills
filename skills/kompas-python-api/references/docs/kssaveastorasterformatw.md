# ksSaveAsToRasterFormatW - Сохранить документ в растровом формате (Unicode)

[API экспортных функций](export_function.html) > [Функции экспорта документов ](impex_fncts_common.html) |  Scroll [ [ [ ](kssaveastouncompressedrasterformat.html "К следующему разделу")](impex_fncts_common.html "На уровень выше")](kssaveastorasterformat.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::SaveAsToRasterFormat](ksdocument2d_saveastorasterformat.html).

Синтаксис:

int LIB_FUNC ksSaveAsToRasterFormatW (reference sheet,

LPWSTR fileName,

RasterFormatParamW * par);

Входные параметры:

sheet | \- указатель на документ,  
---|---  
fileName | \- полное имя файла документа,  
par | \- [структура параметров записи в растровый формат](structrasterformatparamw.html).  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Метод позволяет сохранить присланный документ в растровом формате (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) с заданными свойствами. Cохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

2\. Метод используется для чертежей, фрагментов, спецификаций, деталей и сборок.

3\. Для трехмерной модели предварительно нужно получить reference, используя функцию [ksGetReferenceFrom3dDocument](ksgetreferencefrom3ddocument.html) для COM или свойство [ksDocument3D::reference](ksdocument3d_reference.html) для Automation.

4\. Если параметр sheet=0, сохраняется текущий документ.

5\. При использовании ANSI следует использовать функцию [ksSaveAsToRasterFormat](kssaveastorasterformat.html).

Подразделы:

(отсутствуют)
