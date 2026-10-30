# ksGetStampColumnText - Получить текст ячейки основной надписи

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Основная надпись (Интерфейс ksStamp) ](ksstamp.html) > [ksStamp - методы ](ksstamp_methods.html) |  Scroll [ [ [ ](ksstamp_ksopenstamp.html "К следующему разделу")](ksstamp_methods.html "На уровень выше")](ksstamp_kscolumnnumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksstamp.html)

Аналог данного метода при использовании API экспортных функций - [GetStampColumnText](getstampcolumntext.html).

Синтаксис Automation:

LPDISPATCH ksGetStampColumnText (long* numb);

Выходной параметр:

numb | \- номер ячейки основной надписи.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) строк текста типа TEXT_LINE_ARR или NULL, если все ячейки пройдены.  
---|---  
  
Смотрите также: [ksTextLineParam](kstextlineparam.html)

Примечание:

После выполнения метод смещается на следующую ячейку.

Если номер графы не определен с помощью функции [ksColumnNumber](ksstamp_kscolumnnumber.html), метод начинает работу с первой графы.

После использования полученный массив желательно удалить.

Если numb != NULL, метод возвращает номер графы.

Функция используется в режиме редактирования штампа.

Подразделы:

(отсутствуют)
