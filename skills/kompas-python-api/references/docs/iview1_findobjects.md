# FindObjects - Найти объекты в заданной точке, удовлетворяющие параметрам поиска

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IView1 ](iview1.html) > [IView1 - методы ](iview1_methods.html) |  Scroll [ [ [ ](iview1_isviewpointinbreakview.html "К следующему разделу")](iview1_methods.html "На уровень выше")](iview1_findobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview1.html)

Синтаксис Automation:

VARIANT FindObjects( double X, double Y, double Limit, IFindObjectParameters * Param );

Синтаксис COM:

HRESULT FindObjects( double X, double Y, double Limit, IFindObjectParameters * Param, VARIANT * Result );

Возвращаемое значение:

VARIANT | \- объект типа VARIANT на безопасный массив SAFEARRAY: VT_ARRAY|VT_DISPATCH.  
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
