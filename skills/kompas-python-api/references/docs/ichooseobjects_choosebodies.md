# ChooseBodies - Заменить массив тел (SAFEARRAY)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IChooseObjects ](ichooseobjects.html) > [IChooseObjects - свойства ](ichooseobjects_propers.html) |  Scroll [ [ [ ](ichooseobjects_chooseparts.html "К следующему разделу")](ichooseobjects_propers.html "На уровень выше")](ichooseobjects_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichooseobjects.html)

Тип данных: VARIANT

Синтаксис Automation:

ChooseBodies = Object.ChooseBodies | Получить свойство ([* ](1.html))  
---|---  
Object.ChooseBodies = ChooseBodies | Установить свойство ([* ](1.html))  
ChooseBodies = Object.GetChooseBodies() | Получить свойство ([**](2.html))  
Object.SetChooseBodies( ChooseBodies ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ChooseBodies( &ChooseBodies ) | Получить свойство  
---|---  
Object.put_ChooseBodies( ChooseBodies ) | Установить свойство  
  
Примечание.

Свойство позволяет получать и устанавливать тело или массив тел, участвующих в операции.

Массив возвращается в виде массива SAFEARRAY тел LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
