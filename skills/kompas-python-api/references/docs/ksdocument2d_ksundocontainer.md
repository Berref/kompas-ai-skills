# ksUndoContainer - Включить/отключить объединение операций для Undo

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Редактирование графических объектов ](bt1730357.html) |  Scroll [ [ [ ](bt1730395.html "К следующему разделу")](bt1730357.html "На уровень выше")](ksdocument2d_kslightobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksUndoContainer](ksundocontainer.html).

Синтаксис Automation:

BOOL ksUndoContainer( BOOL add );

Синтаксис COM:

HRESULT ksUndoContainer( BOOL add, BOOL * result );

Входные параметры:

add | \- false - закрывает текущий контейнер Undo для объединения операций, true - создает текущий контейнер Undo для объединения операций.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет включить/отключить объединение операций для Undo.

Подразделы:

(отсутствуют)
