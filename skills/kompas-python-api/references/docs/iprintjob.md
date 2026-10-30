# Интерфейс IPrintJob

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) |  Scroll [ [ [ ](iprintjob_props.html "К следующему разделу")](bh1473974.html "На уровень выше")](bh1473974.html "К предыдущему разделу")  
---|---  
  
Интерфейс задания на печать.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IPrintJob](iprintjob.html)

[IPrintJob_OutputParameters](iprintjob_outputparameters.html)

Описание:

Интерфейс позволяет устанавливать и получать параметры задания на печать.

Термины:

Лист - лист документа.

Страница устройства печати - область печати при заданном размере листов бумаги печатающего устройства.

Примечание:

1\. Интерфейс можно получить у интерфейса приложения КОМПАС с помощью свойства [IApplication::PrintJob](iapplication_printjob.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительный интерфейс [IPrintJob_OutputParameters](iprintjob_outputparameters.html).

Подразделы:

[IPrintJob - свойства ](iprintjob_props.html)

[IPrintJob - методы ](iprintjob_methods.html)

[Интерфейс IPrintJob_Sheet ](iprintjob_sheet_.html)
