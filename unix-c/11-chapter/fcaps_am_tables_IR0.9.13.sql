--------Table Creation--------------
drop table if exists am_collector_host_info;
CREATE TABLE am_collector_host_info(
  collector_id SERIAL PRIMARY KEY NOT NULL,
  collector_name varchar(255) NOT NULL,
  collector_inner_ip varchar(64) NOT NULL,
  collector_external_ip varchar(64) NOT NULL,
  state varchar(24) NOT NULL DEFAULT 'pending',
  heartbeat_time timestamp DEFAULT NULL,
  lost_heartbeat_num integer DEFAULT NULL,
  process_capacity integer NOT NULL,
  node_state varchar(12) NOT NULL
 );

create unique index index_unique_am_collector_host_info_1 on am_collector_host_info (collector_inner_ip);
create unique index index_unique_am_collector_host_info_2 on am_collector_host_info (collector_external_ip);

drop table if exists am_collection_source;
CREATE TABLE am_collection_source(
  source_id    varchar(48)   PRIMARY KEY NOT NULL,
  source_name    varchar(128) DEFAULT NULL,
  source_type    varchar(32) NOT NULL,
  vendor_id    varchar(32) NOT NULL,
  cost_class    varchar(10) NOT NULL,
  collector_id    integer DEFAULT NULL,
  pm_period    integer DEFAULT NULL,
  cm_fm_heartbeat    integer DEFAULT NULL,
  domain_type    varchar(12) DEFAULT NULL,
  ftp_or_sftp    varchar(50) DEFAULT NULL,
  ftp_ip    varchar(50) DEFAULT NULL,
  ftp_port    integer DEFAULT NULL,
  ftp_user    varchar(255) DEFAULT NULL,
  ftp_password    varchar(255) DEFAULT NULL,
  socket_ip    varchar(50) DEFAULT NULL,
  socket_port    integer DEFAULT NULL,
  socket_user    varchar(255) DEFAULT NULL,
  socket_password    varchar(255) DEFAULT NULL,
  state    varchar(12) NOT NULL,
  update_time    timestamp NOT NULL
);

drop table if exists am_collection_source_history;
CREATE TABLE am_collection_source_history(
  auto_id SERIAL PRIMARY KEY NOT NULL,
  source_id    varchar(48) NOT NULL,
  source_name    varchar(128) DEFAULT NULL,
  source_type    varchar(32) NOT NULL,
  vendor_id    varchar(32) NOT NULL,
  cost_class    varchar(10) NOT NULL,
  collector_id    integer DEFAULT NULL,
  pm_period    integer DEFAULT NULL,
  cm_fm_heartbeat    integer DEFAULT NULL,
  domain_type    varchar(12) DEFAULT NULL,
  ftp_or_sftp    varchar(50) DEFAULT NULL,
  ftp_ip    varchar(50) DEFAULT NULL,
  ftp_port    integer DEFAULT NULL,
  ftp_user    varchar(255) DEFAULT NULL,
  ftp_password    varchar(255) DEFAULT NULL,
  socket_ip    varchar(50) DEFAULT NULL,
  socket_port    integer DEFAULT NULL,
  socket_user    varchar(255) DEFAULT NULL,
  socket_password    varchar(255) DEFAULT NULL,
  state    varchar(12) NOT NULL,
  update_time    timestamp NOT NULL
);
        

drop table if exists am_collection_source_cost_class;
CREATE TABLE am_collection_source_cost_class(

  cost_class varchar(10) PRIMARY KEY NOT NULL,
  cost    integer NOT NULL,
  description    varchar(128) DEFAULT NULL
);
insert into am_collection_source_cost_class(cost_class,cost,description) values('A',5,'A level is the minimum load');
insert into am_collection_source_cost_class(cost_class,cost,description) values('B',10,'B level');
insert into am_collection_source_cost_class(cost_class,cost,description) values('C',15,'C level');
insert into am_collection_source_cost_class(cost_class,cost,description) values('D',20,'D level');
insert into am_collection_source_cost_class(cost_class,cost,description) values('E',25,'E level');
insert into am_collection_source_cost_class(cost_class,cost,description) values('F',30,'F level is the maximum load');

drop table if exists am_collection_task_template;
CREATE TABLE am_collection_task_template(
  task_template_id    SERIAL PRIMARY KEY NOT NULL,
  source_type    varchar(32) NOT NULL,
  data_type    varchar(12) NOT NULL,
  pm_period    integer  DEFAULT NULL,
  protocol_type    varchar(12) NOT NULL,
  task_type    varchar(12) NOT NULL,
  api_interface    varchar(100) DEFAULT NULL,
  crontab    varchar(100) DEFAULT NULL,
  ftp_path    varchar(255) DEFAULT NULL,
  status    varchar(10)  NOT NULL,
  update_time    timestamp  NOT NULL
);

insert into am_collection_task_template(source_type,data_type,pm_period,protocol_type,task_type,api_interface,crontab,ftp_path,status,update_time) values('EMS','FM',null,'socket','resident',null,null,null,'valid',NOW());
insert into am_collection_task_template(source_type,data_type,pm_period,protocol_type,task_type,api_interface,crontab,ftp_path,status,update_time) values('VIM','CM',null,'restful','crontab','ListResDetails','0 20 0 * * ?',null,'valid',NOW());
insert into am_collection_task_template(source_type,data_type,pm_period,protocol_type,task_type,api_interface,crontab,ftp_path,status,update_time) values('PIM','CM',null,'restful','crontab','ListResDetails','0 20 0 * * ?',null,'valid',NOW());

drop table if exists am_collection_task;
CREATE TABLE am_collection_task(
  task_id SERIAL PRIMARY KEY NOT NULL,
  task_template_id integer DEFAULT NULL,
  source_id    varchar(48) NOT NULL,
  collector_id    integer NOT NULL,
  source_type    varchar(32) NOT NULL,
  data_type    varchar(12) NOT NULL,
  pm_period    integer  DEFAULT NULL,
  protocol_type    varchar(12) NOT NULL,
  task_type    varchar(12) NOT NULL,
  api_interface    varchar(100) DEFAULT NULL,
  crontab    varchar(100) DEFAULT NULL,
  ftp_path    varchar(255) DEFAULT NULL,
  status    varchar(16)  NOT NULL,
  update_time    timestamp  NOT NULL
);

drop table if exists am_supplement_task;
CREATE TABLE am_supplement_task(
  task_id SERIAL PRIMARY KEY NOT NULL,
  source_id    varchar(48) NOT NULL,
  collector_id    integer NOT NULL,
  source_type    varchar(32) NOT NULL,
  data_type    varchar(12) NOT NULL,
  pm_period    integer  DEFAULT NULL,
  protocol_type    varchar(12) NOT NULL,
  ftp_path    varchar(255) DEFAULT NULL,
  api_interface    varchar(100) DEFAULT NULL,
  start_time    varchar(32) DEFAULT NULL,
  end_time    varchar(32) DEFAULT NULL,
  start_seq    varchar(20) DEFAULT NULL,
  end_seq    varchar(20) DEFAULT NULL,
  status    varchar(16)  NOT NULL,
  update_time    timestamp  NOT NULL
);

drop table if exists am_collection_source_monitor;
CREATE TABLE am_collection_source_monitor(
  source_id    varchar(48) NOT NULL,
  info_type    varchar(10) NOT NULL,
  source_type    varchar(32) NOT NULL,
  alarm_seq    integer DEFAULT NULL,
  heartbeat_time    timestamp DEFAULT NULL,
  update_time    timestamp NOT NULL,
  PRIMARY KEY (source_id,info_type,source_type)
);

drop table if exists vim_alarm;
CREATE TABLE vim_alarm(
  uuid    varchar(32) PRIMARY KEY NOT NULL,
  alarm_id    varchar(36) NOT NULL,
  alarm_seq    integer NOT NULL,
  collect_timestamp    timestamp NOT NULL,
  vendor_id    varchar(6) NOT NULL,
  source_id    varchar(48) NOT NULL,
  alarm_content    text NOT NULL
);

drop table if exists pim_alarm;
CREATE TABLE pim_alarm(
  uuid    varchar(32) PRIMARY KEY NOT NULL,
  alarm_id    varchar(36) NOT NULL,
  alarm_seq    integer NOT NULL,
  collect_timestamp    timestamp NOT NULL,
  vendor_id    varchar(6) NOT NULL,
  source_id    varchar(48) NOT NULL,
  alarm_content    text NOT NULL
);

drop table if exists ems_alarm;
CREATE TABLE ems_alarm(
  uuid    varchar(32) PRIMARY KEY NOT NULL,
  alarm_id    varchar(36) NOT NULL,
  alarm_seq    integer NOT NULL,
  collect_timestamp    timestamp NOT NULL,
  vendor_id    varchar(6) NOT NULL,
  source_id    varchar(48) NOT NULL,
  alarm_content    text NOT NULL
);

---------IR0.9.13 version-----------------------------
drop table if exists am_collection_task_history;
CREATE TABLE am_collection_task_history(
  auto_id SERIAL PRIMARY KEY NOT NULL,
  task_id integer NOT NULL,
  task_template_id integer DEFAULT NULL,
  source_id    varchar(48) NOT NULL,
  collector_id    integer NOT NULL,
  source_type    varchar(32) NOT NULL,
  data_type    varchar(12) NOT NULL,
  pm_period    integer  DEFAULT NULL,
  protocol_type    varchar(12) NOT NULL,
  task_type    varchar(12) NOT NULL,
  api_interface    varchar(100) DEFAULT NULL,
  crontab    varchar(100) DEFAULT NULL,
  ftp_path    varchar(255) DEFAULT NULL,
  status    varchar(16)  NOT NULL,
  update_time    timestamp  NOT NULL
);

----------new version-----------------------------
drop table if exists alarm_sequence_monitor;
CREATE TABLE alarm_sequence_monitor(
  auto_id    SERIAL PRIMARY KEY NOT NULL,  
  source_id varchar(48) NOT NULL,
  start_seq integer  NOT NULL,
  end_seq integer  NOT NULL,
  state varchar(12)  NOT NULL,
  update_time  timestamp  NOT NULL
);