# PathName - Полное имя элемента

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IInsert ](iinsert.html) > [IInsert - свойства ](iinsert_props.html) |  Scroll [ [ [ ](iinsert_methods.html "К следующему разделу")](iinsert_props.html "На уровень выше")](iinsert_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsert.html)

Тип данных: строка

Синтаксис Automation:

PathName = iObject.PathName() | Получить свойство ([* ](1.html))  
---|---  
PathName = iObject.GetPathName() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_PathName (&PathName) | Получить свойство  
---|---  
  
Примечание:

Свойство позволяет получить полное имя вставки вместе с папками внутри библиотеки. Папки отделяются символом "|".

Пример "детали|литье|фланец".

Подразделы:

(отсутствуют)
