# ChooseParts - Массив вставок (SAFEARRAY)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IChooseObjects ](ichooseobjects.html) > [IChooseObjects - свойства ](ichooseobjects_propers.html) |  Scroll [ [ [ ](ichooseobjects_choosepartstype.html "К следующему разделу")](ichooseobjects_propers.html "На уровень выше")](ichooseobjects_choosebodies.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichooseobjects.html)

Тип данных: VARIANT

Синтаксис Automation:

ChooseParts = Object.ChooseParts | Получить свойство ([* ](1.html))  
---|---  
Object.ChooseParts = ChooseParts | Установить свойство ([* ](1.html))  
ChooseParts = Object.GetChooseParts() | Получить свойство ([**](2.html))  
Object.SetChooseParts( ChooseParts ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ChooseParts( &ChooseParts ) | Получить свойство  
---|---  
Object.put_ChooseParts( ChooseParts ) | Установить свойство  
  
Примечание.

Свойство позволяет получать и устанавливать компонент или массив компонентов, участвующих в операции.

Массив возвращается в виде массива SAFEARRAY компонентов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
