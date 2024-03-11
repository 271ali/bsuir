# Документация программной системы

## Введение

Эта программная система представляет собой систему детского сада, включающую в себя различные классы для представления таких сущностей как воспитатель , дети, учебные материалы, родители, развивающие игры;
и операций: операция организации учебного процесса,операция питания и сна, операция взаимодействия с родителями, операция проведения развивающих мероприятий

## Классы и методы

### Класс Person

Базовый класс для представления людей в системе.

#### Методы

- `__init__(self, name, age)`: Инициализация объекта класса Person.
- `get_name(self)`: Возвращает имя человека.
- `get_age(self)`: Возвращает возраст человека.

### Класс Child

Класс для представления детей.

#### Методы

- `__init__(self, name, age)`: Инициализация объекта класса Child.
- `sleep(self)`: Спит.
- `eat(self)`:Ест.
- `play(self, game: EducationalGames)`: Играет.
- `educate(self, material: EducationalMaterials)`: Обучается.
- `get_group_number`: Возвращает номер группы ребенка.
- `get_hungry(self)`: Возвращает значение,которое показывает,голоден ли ребенок.
- `get_sleepy(self)`: Возвращает значение,которое показывает,хочет ли ребенок спать.
- `get_soft_skill(self, skill_name: SoftSkill)`: Возвращает уровень определенного общего навыка.
- `get_hard_skill(self, skill_name: HardSkill)`: Возвращает уровень определенного логического навыка.
- `get_soft_skills(self)`: Возвращает общие навыки.
- `get_hard_skills(self)`: Возвращает логические навыки.
- `set_hungry(self, hungry: bool)`: Устанавливает значение показателя голода ребенка.
- `set_sleepy(self, sleepy: bool)`:  Устанавливает значение показателя желания спать у ребенка.
- `set_group_number(self, group_number: int)`: Устанавливает значение группы ребенка.



### Класс Parent

Класс для представления родителя.

#### Методы

- `__init__(self, name: str, age: int, children: list[Child])`: Инициализация объекта класса Parent.
- `get_children(self)`: Возвращает детей.

### Класс EducationalGame

Класс для представления развивающих игр.

#### Методы

- `__init__(self, name: str, skill: SoftSkill)`: Инициализация объекта класса Presentation.
- `get_name(self)`: Возвращает название игры
- `get_skill(self)`: Возвращает общий навык,который развивает игра.

### Класс EducationalMaterial

Класс для представления учебных материалов.

#### Методы

- `__init__(self, name: str, age: int, skill: HardSkill)`: Инициализация объекта класса EducationalMaterial.
- `get_name(self)`: Возвращает название материала.
- `get_age(self)`: Возвращает минимальный возраст начала изучения.
- `get_skill(self)`: Возвращает логический навык,который развивает материал.

### Класс Kindergartener

Класс для представления воспитателей.

#### Методы

- `__init__(self, name: str, age: int, group_number: int, experience: int, age_range: tuple[int, int])`: Инициализация объекта класса Kindergartener.
- `put_to_bed(self)`: Уложить детей спать.
- `feed(self)`: Накормить детей.
- `play(self, games: list[EducationalGame])`: Распределение детей для игр в зависимости от их навыков.
- `educational_process(self, materials: list[EducationalMaterial])`: Определение для детей учебных материалов в зависимости от возраста.
- `send_the_child_home(self, parent: Parent, child: Child)`: Отправить детей домой.
- `meet_the_child(self, child: Child, parent: Parent)`: Встретить детей.
- `get_experience(self)`: Возвращает опыт работы воспитателем.
- `get_group_number(self)`: Возвращает номер группы.
- `get_group(self)`: Возвращает список группы.
- `get_age_range(self)`: Возвращает возрастные рамки группы.
- `get_present_group(self)`: Возвращает список присутствующих.

### Класс Kindergarten

Класс для представления детского сада.

#### Методы

- `__init__(self, name: str, kindergarteners: list[Kindergartener], educational_plan: list[EducationalMaterial],
                 educational_games: list[EducationalGame], max_group_size: int)`: Инициализация объекта класса Kindergarten.
- `registration(self, group_number: int, child: Child)`: Регистрация ребенка в детском саду.
- `groups_info(self)`: Выводит информацию о группах.
- `pick_up_children(self, parent: Parent)`: Забрать ребенка у родителей.
- `educate(self, group_number: int)`: Обучение.
- `play(self, group_number: int)`: Игры.
- `nutrition(self, group_number: int)`: Питание.
- `nap(self, group_number: int)`: Дневной сон.
- `send_home(self, parent: Parent)`: Отправить детей домой.
- `expel(self, child: Child)`: Исключение из сада.

### Объединение SoftSkill

Объединение возможных базовых и личностных навыков ребенка

#### Объекты

- `communication` : коммуникация
- `physical_endurance` : физическая активность
- `attentiveness` : внимательность
- `patience` : терпение

### Объединение HardSkill

Объединение возможных "профессиональных" и логических навыков ребенка

#### Объекты

- `logics` : логика
- `literacy` : грамотость
- `creativity` : креативность
- `erudition` : кругозор
