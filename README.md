# 이주민 법안 다국어 지원 어플리케이션

이주민에게 제공되는 공공 데이터는 다양하나 실제로 이주민이 접근하고 사용하기에는 여러 가지 한계가 존재 이러한 한계를 시민사회단체에서 생산하는 데이터를 통해 해결해 보자!

<https://www.slideshare.net/YoungchanJeong1/ss-73013730>

<https://www.youtube.com/watch?v=-s356ocFF6Q>


## 개발

<https://github.com/drupal-composer/drupal-project>


### 1. 컴포저 설치 및 composer install

```
# 일단 php는 기본 설치!

# https://getcomposer.org/download/

php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');"
php -r "if (hash_file('SHA384', 'composer-setup.php') === '669656bab3166a7aff8a7506b8cb2d1c292f042046c5a994c43155c0be6190fa0355160742ab2e1c88d40d5be660b410') { echo 'Installer verified'; } else { echo 'Installer corrupt'; unlink('composer-setup.php'); } echo PHP_EOL;"
php composer-setup.php
php -r "unlink('composer-setup.php');"

cd {{ project-root }}
composer install

```

### 2. mysql 데이터베이스 생성 및 복원

```
mysql -u root -p -e 'create database `{{ database name }}` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;'

# 팀에 요청해서 덤프파일 받으세요
mysql -u root -p {{ database name }} < kode-dev.sql
```

### 3. 드루팔 설정 파일 만들기

```
cd {{ project-root }}/web
export PATH="../vendor/bin:$PATH"
cp sites/example.settings.local.php sites/default/settings.local.php
nano sites/default/settings.local.php # 파일 수정하기, 에디터에서 여시던가...
```

```{{ project-root }}/web/sites/default/settings.local.php``` 파일 마지막에 복붙하고 디비나 설정 수정하고 저장

```
$databases['default']['default'] = [
  'database' => 'kode',
  'username' => 'root',
  'password' => 'root',
  'host' => '127.0.0.1',
  'port' => '3306',
  'driver' => 'mysql',
  'prefix' => '',
  'collation' => 'utf8mb4_general_ci',
];

# cd {{ project-root }}/web
# ../scripts/generate_hash.sh

$settings['hash_salt'] = 'FWrYzHfcfA_VOKc_SpYhwGi9iefIr1NuePHwBMlkQmj7z9kfeGO1oU6wKw-MaxVvxQBr7wa-Fw';

$settings['trusted_host_patterns'] = array(
  '^localhost$',
);
```

### 4. 테마 설정하기

```
# nodejs 설치해야 함!
npm -g i gulp-cli bower
npm run setup

```

### 5. 개발 서버 띄우기

```
cd {{ project-root }}/web
drush rs /
# 터미널 새로 여시고 아래 실헹해서 테마 프론트엔드 개발 시작!
cd themes/one/
gulp
```

