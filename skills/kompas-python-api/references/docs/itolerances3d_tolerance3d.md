# Tolerance3D - Указатель на допуск формы 3D, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс ITolerances3D ](itolerances3d.html) > [ITolerances3D - свойства ](itolerances3d_props.html) |  Scroll [ [ [ ](itolerances3d_methods.html "К следующему разделу")](itolerances3d_props.html "На уровень выше")](itolerances3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerances3d.html)

Тип данных: указатель на интерфейс [ITolerance](itolerance.html)

Синтаксис Automation:

Tolerance = iObject.Tolerance( Index ); | Получить свойство ([* ](1.html))  
---|---  
Tolerance = iObject.GetTolerance( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Tolerance( Index, &Tolerance ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
