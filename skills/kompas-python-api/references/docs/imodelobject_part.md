# Part - Компонент, владеющий элементом

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [3D-объект ](bc2229904.html) > [Интерфейс IModelObject ](imodelobject.html) > [IModelObject - свойства ](imodelobject_props.html) |  Scroll [ [ [ ](imodelobject_valid.html "К следующему разделу")](imodelobject_props.html "На уровень выше")](imodelobject_owner.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobject.html)

Тип данных: указатель на интерфейс [IPart7](ipart7.html).

Синтаксис Automation:

Part = iObject.Part | Получить свойство([* ](1.html))  
---|---  
Part = iObject.GetPart( ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

HRESULT Part( [out, retval] IPart7** Result ); | Получить свойство  
---|---  
  
Примечание:

1\. Возвращает указатель на интерфейс компонента, владеющий объектом.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
