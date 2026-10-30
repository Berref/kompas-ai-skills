# Destroy - Разрушить ссылку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IHypertextReferenceParam ](ihypertextreferenceparam.html) > [IHypertextReferenceParam - методы ](ihypertextreferenceparam_methods.html) |  Scroll [ [ [ ](bc1473974.html "К следующему разделу")](ihypertextreferenceparam_methods.html "На уровень выше")](ihypertextreferenceparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ihypertextreferenceparam.html)

Синтаксис Automation:

BOOL Destroy();

Синтаксис COM:

HRESULT Destroy( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Метод позволяет удалить связь между ссылкой и ее источником. В результате разрушения содержимое ссылки становится обычным текстом. Обновление разрушенной ссылки становится невозможным.

Подразделы:

(отсутствуют)
