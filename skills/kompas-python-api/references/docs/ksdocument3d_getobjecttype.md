# GetObjectType - Получить тип объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_getpart.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_getobjparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

long GetObjectType (LPDISPATCH obj);

Синтаксис COM:

int GetObjectType (LPUNKNOWN obj);

Входной параметр:

obj | \- указатель на интерфейс IDispatch или IUnknown трехмерного объекта.  
---|---  
  
Возвращаемое значение:

| \- тип объекта [Obj3dType](obj3dtype.html).  
---|---  
  
Примечания:

Данный метод удобно использовать для приведения базового интерфейса (IUnknown в COM и IDispatch в Automation) к конечному трехмерному интерфейсу. Зная тип объекта, можно привести его к соответствующему интерфейсу.

Подразделы:

(отсутствуют)
