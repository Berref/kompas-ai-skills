# VisualCreateObject - Запустить визуальный процесс создания объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_visualeditobject.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_updateplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

LPDISPATCH VisualCreateObject( ksObj3dTypeEnum ObjectType );

Синтаксис COM:

HRESULT VisualCreateObject( ksObj3dTypeEnum ObjectType, IModelObject * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс объекта I[ModelObjec](imodelobject.html)t.  
---|---  
  
Входные параметры:

ObjectType | \- тип создаваемого объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
