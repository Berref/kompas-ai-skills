# Align - Выравнивание

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextStyle ](itextstyle.html) > [ITextStyle - свойства ](itextstyle_props.html) |  Scroll [ [ [ ](itextstyle_enableline1.html "К следующему разделу")](itextstyle_props.html "На уровень выше")](itextstyle_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextstyle.html)

Тип данных: из перечисления [ksAlignEnum](ksalignenum.html)

Синтаксис Automation:

Align = iObject.Align | Получить свойство([* ](1.html))  
---|---  
iObject.Align = Align | Установить свойство ([* ](1.html))  
Align = iObject.GetAlign() | Получить свойство ([**](2.html))  
iObject.SetAlign (Align) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Align (&Align) | Получить свойство  
---|---  
iObject->put_Align (Align) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить/изменить выравнивание абзацев (по левой границе, по правой границе, центрирование, выравнивание по двум границам).

2\. Свойство используется для стиля, полученного через методы интерфейса [ISpecificationTuning](ispecificationtuning.html).

Подразделы:

(отсутствуют)
