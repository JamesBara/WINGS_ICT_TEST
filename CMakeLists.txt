cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_PROJECT_NAME wings_ict)

include("gcc-arm-none-eabi.cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

enable_language(C)

project(${CMAKE_PROJECT_NAME})

add_executable(${CMAKE_PROJECT_NAME})

target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
   
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
   inc/components/rcc.h
   inc/components/flash.h
   inc/components/gpio.h
   inc/components/i2c.h
   inc/components/rtc.h
   inc/components/pwr.h
   inc/stm32l412.h
   inc/adt7420.h
   inc/pid.h

   src/startup.c
   src/nvic_it_handlers.c
   src/bsp.c
   src/adt7420.c
   src/pid.c
   src/main.c
)


target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    CMSIS_6/CMSIS/Core/Include
    inc
    inc/components
    )


target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
            
)

target_link_libraries(${CMAKE_PROJECT_NAME}

)

add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        VERBATIM
        #COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
        #COMMAND ${CMAKE_SIZE} ${PROJECT_NAME}.elf
        #COMMAND ${CMAKE_OBJDUMP} -h ${PROJECT_NAME}.elf
        )