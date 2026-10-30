# ksHatch - Создать штриховку с заданными параметрами

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](kshatchex.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](ksellipsearc.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksmakeenclosecontours_kshatch_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksHatchByParam](ksdocument2d_kshatchbyparam.html).

Синтаксис:

reference ksHatch (HatchParam * par);

Входной параметр:

par | \- указатель на [структуру параметров штриховки HatchParam](structhatchparam.html).  
---|---  
  
Возвращаемое значение:

указатель на штриховку | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Объекты границы штриховки лежат во временной группе pBoundaries. После выполнения функции ksHatch временная группа прекращает существование.

Подразделы:

(отсутствуют)
