# stringFlag - Тип используемого массива строк

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Размерная надпись (Интерфейс ksDimTextParam) ](ksdimtextparam.html) > [ksDimTextParam - свойства ](ksdimtextparam_props.html) |  Scroll [ [ [ ](ksdimtextparam_style.html "К следующему разделу")](ksdimtextparam_props.html "На уровень выше")](ksdimtextparam_sign.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdimtextparam.html)

Тип данных:BOOL.

Значения свойства:

FALSE | \- тип CHAR_STR_ARR - динамический массив строк символов,  
---|---  
TRUE | \- тип TEXT_LINE_ARR - динамический массив строк текста.  
  
Синтаксис Automation:

stringFlag = iDimText.stringFlag | Получить свойство ([* ](1.html))  
---|---  
iDimText.stringFlag = stringFlag | Установить свойство ([* ](1.html))  
stringFlag = iDimText.GetStringFlag() | Получить свойство ([**](2.html))  
iDimText.SetStringFlag( stringFlag ) | Установить свойство ([**](2.html))  
  
Примечание:

Для функции [ksDocument2D::ksGetObjParam](ksdocument2d_ksgetobjparam.html) нужно определить свойство stringFlag.

Смотрите также:

– [ksDimTextParam::SetTextArr](ksdimtextparam_settextarr.html)

– [ksDimTextParam::GetTextArr](ksdimtextparam_gettextarr.html)

Подразделы:

(отсутствуют)
