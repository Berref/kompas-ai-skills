# TextDown - Текст расположен в нижней части колонки

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_useforsectiontitle.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_stamplinkid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: BOOL

Синтаксис Automation:

TextDown = iObject.TextDown | Получить свойство ([* ](1.html))  
---|---  
TextDown = iObject.GetTextDown() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TextDown (&TextDown) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- в колонке однострочные тексты будут располагаться в той строке, в которой кончается текст предыдущей колонки,  
---|---  
FALSE | \- тексты будут располагаться в верхней части колонки.  
  
Примечание:

1\. Чаще всего эту опцию включают при настройке колонки Количество, когда требуется, чтобы количество было записано в той строке, где заканчивается наименование.

2\. Используется только для основных колонок спецификации.

3\. Используется только для колонок, полученных у стиля спецификации [ISpecificationStyle](ispecificationstyle.html).

4\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
