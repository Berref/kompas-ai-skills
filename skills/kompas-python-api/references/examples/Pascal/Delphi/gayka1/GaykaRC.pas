unit GaykaRC;

interface

const

 ID_VIEW          =  1;   // вид основной        // ID_VID
 ID_SEC           =  2;   // вид основной разрез // ID_SEC
 ID_TOP           =  3;   // вид сверху
 ID_TOP_SEC       =  4;   // вид сверху разрез
 ID_LEFT          =  5;   // вид слева
 ID_LEFT_SEC      =  6;   // вид слева разрез
 ID_RIGHT         =  7;   // вид справа
 ID_RIGHT_SEC     =  8;   // вид справа разрез
 ID_BOTTOM        =  9;   // вид снизу
 ID_BOTTOM_SEC    = 10;   // вид снизу разрез
 ID_SIDE          = 11;   // вид спереди
 ID_SIDE_SEC      = 12;   // вид спереди разрез
 ID_BACK          = 13;   // вид сзади
 ID_BACK_SEC      = 14;   // вид сзади разрез





 ID_SIMPLE                   = 200;    // Упрощенно
 ID_AXIS                     = 201;    // Рисовать ось
 WORKWINDOWCOLOR             = $0fe000000;  // признак назначенности цвета рабочего окна

 CM_GAYKA5915                =   1;


 ID_LEADER_CONNECT           =   300;
 ID_LEADER_CREATE            =   301;
 ID_ERROR_LEADER             =   302;
 ID_INDICATE_LEADER          =   303;
 ID_ERROR_2DDOC              =   304;

 IDS_API7                    =   900;
 IDS_API7LT                  =   901;


 ID_GAYKA_BMP                =   1001;
 IDP_LEADER_BUTTONS          =   1002; // "Создать новую"
 IDP_POS_LEADER              =   1003; // "Ввод линии выноски"

 IDP_ELEMENT_PARAM           =   4000;
 IDP_GAYKA5915               =   4002;
 IDP_HATCH_PARAM             =   5000;
 IDP_HATCHANG_ANGLE          =   5001;
 IDP_HATCHANG_STEP           =   5002;
 IDP_DIAM                    =   5003;
 IDP_REFLECTION              =   5004;
 IDP_ISP                     =   5005;
 IDP_FLAGS                   =   5006;
 IDP_SIMPLE                  =   5007;
 IDP_SPC_OBJ                 =   5008;
 IDP_BMP_AXIS                =   ID_AXIS;
 IDP_BMP_KEY                 =   6002;
 IDP_BMP_G_VIEW              =   6003;
 IDP_BMP_G_LEFT              =   6004;
 IDP_BMP_G_TOP               =   6005;
 IDP_BMP_G_SEC               =   6006;
 IDP_BMP_G_I1                =   6007;
 IDP_BMP_G_I2                =   6008;
 IDP_BMP_G_SIMPLE            =   6009;
 IDP_BMP_G_STEP              =   6010;
 IDP_C_VCHATCH               =   7000;

 IDS_PARAM_CAPTION           =   9000;        // "Параметры"
 IDS_VALUE_CAPTION           =   8001;        // "Значения"
 IDS_PITCH                   =   8002;        // "Шаг резьбы"
 IDS_DIM_KEY                 =   IDP_BMP_KEY; // "Размер под ключ"
 IDS_HEAD_H                  =   8003;        // "Высота головки"
 IDS_MASSA_1000              =   8004;        // "Масса 1000 шт"
 IDS_CUPNUT_STR1             =   8005;        // "D Диметр колпачка, мм"
 IDS_CUTGAY_STR9             =   8006;        // "e Диаметр описанной окружности, мм"
 IDS_CUPNUT_STR2             =   8007;        // "h1 Высота под ключ, мм"
 IDS_CUPNUT_STR3             =   8008;       // "l Глубина отверстия, мм"
 IDS_CUPNUT_STR4             =   8009;        // "l1 Длина резьбы, мм"
 IDS_DIM_KEY_2               =   8010;        // "Дополнительный размер под ключ"
 IDS_DIAM_TIPS               =   8011;
 IDS_DIAM_HINT               =   8012;
 IDS_REFLECTION_TIPS         =   8013;
 IDS_REFLECTION_HINT         =   8014;
 IDS_ISP_TIPS                =   8015;
 IDS_ISP_HINT                =   8016;
 IDS_SIMPLE_TIPS             =   8017;
 IDS_SIMPLE_HINT             =   8018;
 IDS_FLAGS_TIPS              =   8019;
 IDS_SPC_OBJ_TIPS            =   8020;
 IDS_LEADER_HINT             =   8021;
 IDS_LEADER_TIPS             =   8022;


 ID_LIBID                    =  1000;

 CURSOR_ROTATE               =  10011;
 CURSOR_DIAMETER             =  10012;

  SPC_FORMAT    = 1;     // формат
  SPC_ZONA      = 2;     // зона
  SPC_POSITION  = 3;     // позиция
  SPC_MARKER    = 4;     // обозначение
  SPC_NAME      = 5;     // наименование
  SPC_COUNT     = 6;     // количество
  SPC_NOTE      = 7;     // примечание

  BASE_LINE     = 1;     // тип основной линии
  SLIM_LINE     = 2;     // тонкая линия
  AXIS_LINE     = 3;     // тип осевой линии
  AXIS_END      = 3;     // величина выступания осевой линии за габарит тела


  STANDART_SECTION = 25; // номер раздела стандартных изделий

  LIB_HELPFILE     = 'gayka.chm'; // имя файла помощи
  SPC_LIB          = 'graphic.lyt';

  MIN_H_ANG        = -90;
  MAX_H_ANG        =  90;
  MIN_H_SHAG       = 0.1;
  MAX_H_SHAG       = 1000;

  SPCOBJ_CREATE    = true; // признак подключения объекта к спецификации
  MAX_COUNT_SPCOBJ = 4;    // максимальное число объектов СП за раз 4
  COUNT_MASSA      = 1000; // количество элементов для которых задана масса

// BaseMakroParam.flags
  BF_ATTR      : Byte = $1;    // создавать объект спецификации
  BF_SIMPLE    : Byte = $2;    // упрощенное изображение
  BF_AXIS      : Byte = $4;    // рисовать ось
  BF_DIMENSION : Byte = $8;    // с размерами или без


// тип предпросмотра
// type PreviewType = ( ptGroup, ptSlide, ptNone );

// вид элемента
//type ElementView =  evMain,  evMainCut,  evTop,    evTopCut,    evLeft, evLeftCut,
//                    evRight, evRightCut, evBottom, evBottomCut, evSide, evSideCut,
//                    evBack,  evBackCut };

implementation

end.
