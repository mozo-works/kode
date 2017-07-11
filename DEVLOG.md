# 개발 일지

## 2017-07-10

### 1. 페이스북 로그인 추가

#### simple_fb_connect 모듈 추가

- 프로젝트: https://www.drupal.org/project/simple_fb_connect
- ``` $ composer require drupal/simple-fb-connect ```

#### 페북 앱 생성 및 설정

- (rooty-dev) 페북 앱아이디, 크레덴셜, 도메인 등 설정 (설치 문서 참고)
- 설치문서: https://www.drupal.org/docs/8/modules/simple-fb-connect/installation-instructions

### 2. certbot https

- ec2 security group inboud rule에 tcp 443 anywhere 추가
- https://certbot.eff.org/all-instructions/#ubuntu-16-04-xenial-apache

```
$ sudo apt-get update
$ sudo apt-get install software-properties-common
$ sudo add-apt-repository ppa:certbot/certbot
$ sudo apt-get update
$ sudo apt-get install python-certbot-apache 

$ sudo certbot --apache
```

* 무조건 https로 리다이렉트

https://wiki.apache.org/httpd/RedirectSSL



