# Tolerance - Указатель на допуск формы, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс ITolerances ](itolerances.html) > [ITolerances - свойства ](itolerances_props.html) |  Scroll [ [ [ ](itolerances_methods.html "К следующему разделу")](itolerances_props.html "На уровень выше")](itolerances_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerances.html)

Тип данных: указатель на интерфейс [ITolerance](itolerance.html)

Синтаксис Automation:

Tolerance = iObject.Tolerance( Index ); | Получить свойство([* ](1.html))  
---|---  
Tolerance = iObject.GetTolerance( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Tolerance( Index, &Tolerance ) | Получить свойство  
---|---  
  
Входные параметры:

Index | VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
