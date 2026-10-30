# FindObject - Найти объект, ближайший к заданной точке, удовлетворяющий параметрам поиска

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IView1 ](iview1.html) > [IView1 - методы ](iview1_methods.html) |  Scroll [ [ [ ](iview1_findobjects.html "К следующему разделу")](iview1_methods.html "На уровень выше")](iview1_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview1.html)

Синтаксис Automation:

LPDISPATCH FindObject( double X, double Y, double Limit, IFindObjectParameters * Param );

Синтаксис COM:

HRESULT FindObject( double X, double Y, double Limit, IFindObjectParameters * Param, IDrawingObject * * Result );

Возвращаемое значение:

указатель на интерфейс [IDrawingObject](idrawingobject.html). |   
---|---  
  
Входные параметры:

X | \- первая координата точки,  
---|---  
Y | \- вторая координата точки,  
Limit | \- предел поиска и найденное расстояние,  
Param | \- параметры поиска объектов [IFindObjectParameters](ifindobjectparameters.html).  
  
Примечание:

Для поиска объектов в точке могут быть заданы расширенные параметры поиска.

Интерфейс расширенных параметров поиска [IFindObjectParameters](ifindobjectparameters.html) можно получить с помощью метода [IKompasDocument1::GetInterface;](ikompasdocument1_getinterface.html)  
в 2D документах при использовании константы ksObjectFindObjectParameters.

Если расширенные параметры поиска не требуются, необходимо передать NULL в функцию.

Подразделы:

(отсутствуют)
