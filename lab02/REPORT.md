## Laboratory work II

Данная лабораторная работа посвящена изучению утилит для разработки проектов

## Tasks

- [X] 1. Ознакомиться со ссылками учебного материала
- [X] 2. Выполнить инструкцию учебного материала
- [x] 3. Составить отчет и отправить ссылку личным сообщением в **Slack**
 
## Tutorial

Устанавливаем значения переменные окружений `GITHUB_USERNAME` и `GIST_TOKEN`, затем настраиваем текстовый редактор.
```bash
$ export GITHUB_USERNAME=TalkedDevotee # Установка значения GITHUB_USERNAME
$ export GIST_TOKEN=47fb03c84a3c68409f7ff2cf3732408231bc8624 # Установка значения GIST_TOKEN
$ alias edit=vim # Настройка текстового редактора
```

```bash
$ npm install -g gistup
```

Создаем файл .gistup.json и в нем прописываем `token`.
```bash
$ cat > ~/.gistup.json <<EOF
{
  "token": "${GIST_TOKEN}"
}
EOF
```

Создаем три папки.
```bash
$ cd ~ # Переход в домашнюю папку
$ mkdir -p workspace/labs/projects/ # Создание папки projects
$ mkdir -p workspace/labs/tasks/ # Создание папки tasks
$ mkdir -p workspace/labs/reports/ # Создание папки reports
```

## Report


Скачиваем папку с файлами с GitHub, создаем новую папку, копируем файл README.md под другим именем в только что созданную папку, редактируем файл и выкладываем обратно на сервер.
```bash
$ cd ~/workspace/labs/ # Переход в папку labs
$ export LAB_NUMBER=02 # Установка значения LAB_NUMBER
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER} # Скачиваем с сайта
$ mkdir reports/lab${LAB_NUMBER} # Создаем папку lab02
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md # Копируем файл README.md в папку lab02 под новым именем с расширением .md
$ cd reports/lab${LAB_NUMBER} # Переход в папку lab02
$ edit REPORT.md # Редактируем файл
$ gistup -m "lab${LAB_NUMBER}" # Коммит "lab02"
```

## Links

### Unix commands

- [ar](https://en.wikipedia.org/wiki/Ar_(Unix))
- [cat](https://en.wikipedia.org/wiki/Cat_(Unix))
- [cd](https://en.wikipedia.org/wiki/Cd_(command))
- [cp](https://en.wikipedia.org/wiki/Cp_(Unix))
- [cut](https://en.wikipedia.org/wiki/Cut_(Unix))
- [echo](https://en.wikipedia.org/wiki/Echo_(command))
- [env](https://en.wikipedia.org/wiki/Env_(shell))
- [ex](https://en.wikipedia.org/wiki/Ex_(editor))
- [file](https://en.wikipedia.org/wiki/File_(command))
- [find](https://en.wikipedia.org/wiki/Find)
- [ls](https://en.wikipedia.org/wiki/Ls)
- [man](https://en.wikipedia.org/wiki/Man_page)
- [mkdir](https://en.wikipedia.org/wiki/Mkdir)
- [mv](https://en.wikipedia.org/wiki/Mv)
- [nm](https://en.wikipedia.org/wiki/Nm_(Unix))
- [ps](https://en.wikipedia.org/wiki/Ps_(Unix))
- [pwd](https://en.wikipedia.org/wiki/Pwd)
- [rm](https://en.wikipedia.org/wiki/Rm_(Unix))
- [sed](https://en.wikipedia.org/wiki/Sed)
- [touch](https://en.wikipedia.org/wiki/Touch_(Unix))

### Package Managers

- [apt](http://help.ubuntu.ru/wiki/apt) | [dnf](https://en.wikipedia.org/wiki/DNF_(software)) | [yum](https://fedoraproject.org/wiki/Yum/ru)
- [brew](https://brew.sh) | [linuxbrew](http://linuxbrew.sh)
- [npm](https://docs.npmjs.com)

### Software

- [curl](https://www.gitbook.com/book/bagder/everything-curl/details)
- [wget](https://www.gnu.org/software/wget/manual/wget.pdf)
- [clang](https://clang.llvm.org)
- [g++](https://gcc.gnu.org/onlinedocs/gcc-4.0.2/gcc/G_002b_002b-and-GCC.html)
- [make](https://en.wikipedia.org/wiki/Make_(software))
- [open](https://developer.apple.com/legacy/library/documentation/Darwin/Reference/ManPages/man1/open.1.html)
- [openssl](https://www.openssl.org)
- [nano](https://www.nano-editor.org)
- [tree](https://linux.die.net/man/1/tree)
- [vim](http://www.vim.org)

```
Copyright (c) 2017 Братья Вершинины
```

