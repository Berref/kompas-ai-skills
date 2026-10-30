# InstanceCount - Количество вставок компонента

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - свойства ](ipart7_props.html) |  Scroll [ [ [ ](ipart7_isbillet.html "К следующему разделу")](ipart7_props.html "На уровень выше")](ipart7_inheritvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

[Пример...](partsex_instancecount_example.html)

Тип данных: long

Синтаксис Automation:

Count = iObject.InstanceCount( iPart7 ) | Получить свойство ([* ](1.html))  
---|---  
Count = iObject.GetInstanceCount( iPart7 ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_InstanceCount( iPart7, &Count ) | Получить свойство  
---|---  
  
Входные параметры:

iPart7 | \- указатель на компонент или NULL.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Метод работает для верхнего компонента сборки и для вставок подсборок. Если iPart7 == NULL, то возвращается общее количество компонентов, вставленных в данную подсборку.

Подразделы:

(отсутствуют)
