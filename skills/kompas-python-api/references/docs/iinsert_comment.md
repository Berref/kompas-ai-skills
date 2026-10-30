# Comment - Комментарий

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IInsert ](iinsert.html) > [IInsert - свойства ](iinsert_props.html) |  Scroll [ [ [ ](iinsert_inserttype.html "К следующему разделу")](iinsert_props.html "На уровень выше")](iinsert_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsert.html)

Тип данных: VARIANT

Синтаксис Automation:

Comment = iObject.Comment | Получить свойство ([* ](1.html))  
---|---  
iObject.Comment = Comment | Установить свойство ([* ](1.html))  
Comment = iObject.GetComment() | Получить свойство ([**](2.html))  
iObject.SetComment (Comment) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Comment (&Comment) | Получить свойство  
---|---  
iObject->put_Comment (Comment) | Установить свойство  
  
Примечание:

Позволяет получить и установить комментарий для вставки. Комментарий может быть многострочным. Поэтому свойство возвращает или принимает переменную типа VARIANT на безопасный массив строк SAFEARRAY (VT_ARRAY | VT_BSTR).

Подразделы:

(отсутствуют)
