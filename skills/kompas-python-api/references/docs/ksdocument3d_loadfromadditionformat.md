# LoadFromAdditionFormat - Загрузить документ из дополнительных форматов jgs, sat, xt, x_b, step, stl, jt, C3D

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_mateconstraintcollection.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_kssetobjparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL LoadFromAdditionFormat( BSTR fileName, LPDISPATCH additionPar );

Синтаксис COM:

BOOL LoadFromAdditionFormat( LPOLESTR fileName, LPADDITIONFORMATPARAM additionPar );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

fileName | \- имя файла,  
---|---  
additionPar | \- указатель на интерфейс [ksAdditionFormatParam](ksadditionformatparam.html) или IAdditionFormatParam, определяющий параметры записи в дополнительный формат,  
  
Подразделы:

(отсутствуют)
