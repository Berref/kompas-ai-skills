# AutoTransparentBackground - Включение/отключение управления очисткой фона под объектом через настройку документа

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IDrawingObject1 ](idrawingobject1.html) > [IDrawingObject1 - свойства ](idrawingobject1_props.html) |  Scroll [ [ [ ](idrawingobject1_constraints.html "К следующему разделу")](idrawingobject1_props.html "На уровень выше")](idrawingobject1_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobject1.html)

Тип данных: BOOL

Синтаксис Automation:

AutoTransparentBackground = Object.AutoTransparentBackground | Получить свойство([* ](1.html))  
---|---  
Object.AutoTransparentBackground = AutoTransparentBackground | Установить свойство ([* ](1.html))  
AutoTransparentBackground = Object.GetAutoTransparentBackground() | Получить свойство ([**](2.html))  
Object.SetAutoTransparentBackground( AutoTransparentBackground ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AutoTransparentBackground( &AutoTransparentBackground ) | Получить свойство  
---|---  
Object.put_AutoTransparentBackground( AutoTransparentBackground ) | Установить свойство  
  
Значение свойства:

TRUE | \- включено управление очисткой фона через настройку документа,  
---|---  
FALSE | \- отключено управление очисткой фона через настройку документа.  
  
Примечание:

Позволяет включить/отключить признак подчинения очистки фона под аннотационными объектами [DrawingObject1::TransparentBackground](idrawingobject1_transparentbackground.html) настройкам документа.

Подразделы:

(отсутствуют)
