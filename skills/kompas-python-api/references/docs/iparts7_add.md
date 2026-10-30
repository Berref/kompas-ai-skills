# Add - Создать новый компонент и добавить его в документ и коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - методы ](iparts7_methods.html) |  Scroll [ [ [ ](iparts7_addfromfile.html "К следующему разделу")](iparts7_methods.html "На уровень выше")](iparts7_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Синтаксис Automation:

LPDISPATCH Add( LPCTSTR FileName, LPDISPATCH plane );

Синтаксис COM:

HRESULT Add([in] BSTR FileName, [in] IModelObject * Plane, [out, retval] IPart7 ** Result);

Входные параметры:

FileName | \- имя файла детали, создаваемой в сборке,  
---|---  
Plane | \- указатель на интерфейс плоского объекта, к которому приклеивается деталь.  
  
Возвращаемое значение:

указатель на интерфейс [IPart7](ipart7.html) | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
