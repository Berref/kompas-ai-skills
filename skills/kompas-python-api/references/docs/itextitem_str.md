# Str - Текстовое значение компоненты текста

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextItem ](itextitem.html) > [ITextItem - свойства ](itextitem_props.html) |  Scroll [ [ [ ](itextitem_symbolfontname.html "К следующему разделу")](itextitem_props.html "На уровень выше")](itextitem_sizefactor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextitem.html)

Тип данных: BSTR(строка)

Синтаксис Automation:

Str = iObject.Str; | Получить свойство([* ](1.html))  
---|---  
iObject.Str = Str; | Установить свойство ([* ](1.html))  
Str = iObject.GetStr(); | Получить свойство ([**](2.html))  
iObject.SetStr(Str); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Str(&Str); | Получить свойство  
---|---  
iObject->put_Str(Str); | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить текст в виде массива символов.

2\. Это свойство не используется для компонент типа ksTItSpecialSymbol и ksTItFontSymbol из перечисления [ksTextItemEnum](kstextitemenum.html).

Подразделы:

(отсутствуют)
