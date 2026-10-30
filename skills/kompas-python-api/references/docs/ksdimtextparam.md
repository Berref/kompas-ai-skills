# Размерная надпись (Интерфейс ksDimTextParam)

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) |  Scroll [ [ [ ](ksdimtextparam_props.html "К следующему разделу")](cf1713887.html "На уровень выше")](ksdimensionpartsparam_init.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров размерной надписи.

Аналог данных параметров при использовании API экспортных функций - [DimText](structdimtext.html).

Примечание:

1\. Строки в массив ложатся в следующей последовательности:

Префикс. Если он добавлен, в bitFlag взводится признак _PREFIX,

Номинальное значение зависит от флагов _AUTONOMINAL и _NOMINALOFF.

Номинальное значение добавляется, если _AUTONOMINAL и _NOMINALOFF выключены.

Квалитет _TOLERANCE.

Верхнее и нижнее отклонения _DEVIATION и _DEVIATION_INFORM.

Единицы измерения _UNIT.

Текст после _SUFFIX.

Остальные строки это текст после.

2\. Если флаг TOLERANCE включен, то значения отклонений не устанавливаются независимо от наличия их в массиве. Они воспринимаются как информационные.

3\. Перед вызовом GetObjParam нужно установить stringFlag в 0, если нужно получить массив строк символов CHAR_STR_ARR, или в 1, если нужно получить массив текстов TEXT_LINE_ARR. Для того, чтобы добавить верхнее и нижнее отклонение, нужно рассчитать индекс с учетом включенных или выключенных флагов _PREFIX, _AUTONOMINAL, _NOMINALOFF, и TOLERANCE. Также нужно проверить, включен уже флаг _DEVIATION или нет. Если включен TOLERANCE, данный элемент нужно будет удалить.

4\. Динамический массив TEXT_LINE_ARR содержит структуру TextLineParam.

Указатель на интерфейс можно получить при помощи метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html).

Смотрите также: [KompasObject](kompasobject.html)

Подразделы:

[ksDimTextParam - свойства ](ksdimtextparam_props.html)

[ksDimTextParam - методы ](ksdimtextparam_methods.html)
