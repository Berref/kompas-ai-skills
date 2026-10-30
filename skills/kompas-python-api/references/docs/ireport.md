# Интерфейс IReport

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Таблицы отчетов ](ba1858294.html) |  Scroll [ [ [ ](ireport_props.html "К следующему разделу")](ba1858294.html "На уровень выше")](ba1858294.html "К предыдущему разделу")  
---|---  
  
Интерфейс таблицы отчетов.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IReport](ireport.html)

Интерфейс можно получить у интерфейса ассоциативной таблицы при помощи свойства [IAssociationTable::Report](iassociationtable_report.html) или у интерфейса Менеджера свойств при помощи метода [IPropertyMng::GetReport](ipropertymng_getreport.html).

Посредством вызова метода [Unknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительные интерфейсы:

•[IReportParam](ireportparam.html) – Интерфейс параметров отчета,

•[IReportTable](ireporttable.html) – Интерфейс таблицы данных,

•[IChooseManager](ichoosemanager.html) – Интерфейс менеджера выбора (подсветки) объектов.

Подразделы:

[IReport - свойства ](ireport_props.html)

[IReport - методы ](ireport_methods.html)
