# IncludeGeometry - Добавить геометрию к объекту спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - методы ](ispecificationbaseobject_methods.html) |  Scroll [ [ [ ](ispecificationbaseobject_setmaterial.html "К следующему разделу")](ispecificationbaseobject_methods.html "На уровень выше")](ispecificationbaseobject_cleargeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Синтаксис Automation:

BOOL IncludeGeometry( VARIANT PVal, BOOL FillText );

Синтаксис COM:

HRESULT IncludeGeometry( VARIANT PVal, BOOL FillText, BOOL * Result );

Входные параметры:

PVal | \- Объект VT_DISPATCH или список объектов VT_ARRAY | VT_DISPATCH,  
---|---  
FillText | \- признак автоматического заполнения колонок: наименование, обозначение, масса взяты из свойств объекта.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Если при подключении компонента присылается флаг fillTexts = true, в объекте спецификации взводится флаг [ISpecificationBaseObject::SyncronizeWithProperties](ispecificationbaseobject_syncronizewithproperties.html).

Подразделы:

(отсутствуют)
