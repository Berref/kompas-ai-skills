# ksDrawKompasDocument - Показать КОМПАС-документ в виде слайда в окне

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksdrawkompasdocumentw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksdrawbitmapex.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksdrawkompasdocument_example.html)

Синтаксис:

int ksDrawKompasDocument ( void * HWindow, char * docFileName );

Входные параметры:

HWindow | \- дескриптор окна просмотра,  
---|---  
docFileName | \- полное имя файла документа.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Действие функции распространяется также на фрагменты и модели из библиотек. При этом имя файла должно иметь вид "c:\gr\lib1.l3d|детали|литье|фланец",

где:

– c:\gr\lib1.l3d - имя файла библиотеки,

– |детали|литье| - разделы, подразделы внутри библиотеки,

– фланец - имя фрагмента или модели.

2\. При использовании Unicode следует использовать функцию [ksDrawKompasDocumentW](ksdrawkompasdocumentw.html).

Подразделы:

(отсутствуют)
