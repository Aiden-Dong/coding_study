package com.saligia.dao;

import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Update;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-08-29
 */
public interface UserAutoDefineMapper {
    @Update("${sql}")  // 完全替换 （${..} -> sql）
    public void action(@Param("sql") String sql);
}
